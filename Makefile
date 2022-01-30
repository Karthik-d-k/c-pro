## build        : Build the site
.PHONY : build
build : 
	mkdocs build

## new          : Create new site
.PHONY : new
new : 
	mkdocs new .

## serve        : Preview site locally
.PHONY : serve
serve : 
	mkdocs serve

.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<

# resource + motivation :- \
Mike Jackson (ed.): "Software Carpentry: Automation and Make." \
Version 2016.06, June 2016, \
https://github.com/swcarpentry/make-novice, 10.5281/zenodo.57473.
