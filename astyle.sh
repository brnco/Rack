#!/bin/sh

# Requires Artistic Style 3.1
# http://astyle.sourceforge.net/

astyle --suffix=none \
	--style=java \
	--indent=tab \
	--indent-switches \
	--attach-closing-while \
	--pad-oper \
	--pad-comma \
	--pad-header \
	--unpad-paren \
	--align-pointer=name \
	--align-reference=name \
	--break-closing-braces \
	--break-one-line-headers \
	--attach-return-type \
	--attach-return-type-decl \
	--close-templates \
	$@
