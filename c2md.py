from pathlib import Path

path = Path.cwd()

inputdir = path/'_src'
outputdir = path/'docs'

doc_string = """# problem_statement

``` c

--8<-- "filename"

```
"""

def get_paths(inputdir, pattern):
    for path in Path(inputdir).rglob(pattern):
        if path.exists():
            yield path

def get_files(paths, pattern):
    for path in paths:
        with path.open(pattern, encoding='utf8') as f:
            yield f

def get_contents(files):
    for f in files:
        yield f.read()

def get_statements(contents):
    for content in contents:
        content = ' '.join(content.partition("/*")[2].split())
        content = ' '.join(content.partition("*/")[0].split())
        yield content

def create_md_paths(c_files):
    for c_file in c_files:
        dir_name = (c_file).parent
        out_dir_name = Path(str(dir_name).replace('_src', 'docs'))
        if not out_dir_name.is_dir():
            out_dir_name.mkdir()
        md_file = Path(out_dir_name/c_file.name).with_suffix('.md')
        yield md_file

def write_statements(md_files, statements, doc):
    for f, statement in zip(md_files, statements):
        doc_string = doc
        doc_string = doc_string.replace('problem_statement', statement)
        filename = f.name.split('/')[-1].replace('.md', '.c')
        doc_string = doc_string.replace('filename', filename)
        f.write(doc_string)

if (__name__ == "__main__"):
    paths = get_paths(inputdir, '*.c')
    files = get_files(paths, 'rt')
    data = get_contents(files)
    statements = get_statements(data)
    c_files = get_paths(inputdir, '*.c')
    md_paths = create_md_paths(c_files)
    md_files = get_files(md_paths, 'wt')
    write_statements(md_files, statements, doc_string)
