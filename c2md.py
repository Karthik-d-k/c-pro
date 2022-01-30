import os
from pathlib import Path

path = Path.cwd()

inputpath = path/'_src'
outputpath = path/'docs'

doc_string = """# problem_statement

``` c

--8<-- "filename.c"

```
"""

c_files = inputpath.rglob('*.c')

def extract_statement(c_file):
    """
    Extract problem statement from the given `c_file`.
    """
    statement_string = ""
    with open(c_file, mode='r', encoding='utf8') as f:
            for lineno, line in enumerate(f, start=1):
                if ('#include' not in line) and lineno <= 3 :
                    statement_string += line.strip()
    # delete comment indicator                 
    statement_string = statement_string.replace("/*", "", 1)
    statement_string = statement_string.replace("*/", "", 1)
    # remove whitespaces
    statement_string = statement_string.strip()
    return statement_string

def c2md(c_files):
    """
    Create .md file for the given `c_files` inside docs folder.
    """
    for c_file in c_files:
        dir_name = (c_file).parent
        out_dir_name = Path(str(dir_name).replace('_src', 'docs'))
        if not os.path.isdir(out_dir_name):
            os.mkdir(out_dir_name)
        md_file = Path(out_dir_name/c_file.name).with_suffix('.md')
        statement_string = extract_statement(c_file)
        with open(md_file, mode='w', encoding='utf8') as f:
            f.truncate(0)
            string = doc_string.replace('problem_statement', statement_string)
            code = string.replace('filename', str(md_file.name[:-3]))
            f.write(code)

if (__name__ == "__main__"):
    c2md(c_files)
