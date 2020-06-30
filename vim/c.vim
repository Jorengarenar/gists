" BUGGY C SYNTAX RULES
" vim: fen fdm=marker

" Fold K&R/Allman/GNU... style {{{1

syntax clear  cBlock
syntax region cBlockImp start=/\%(\/.*\)\@!.\n\?{/ start=/\/.*\n{/ end=/}/ transparent fold contains=ALLBUT,cBadBlock,cCurlyError,@cParenGroup,cErrInParen,cErrInBracket

" Version including new empty line
" syntax region cBlockImp start=/\%(\/.*\)\@!.\n\?{/ start=/\/.*\n{/ end=/}/ end=/}\n\n/ end=/^}.*;\n\n/ transparent fold contains=ALLBUT,cBadBlock,cCurlyError,@cParenGroup,cErrInParen,cErrInBracket


" Fold switch case {{{1

syntax clear cLabel cStatement

syntax keyword cStatement   asm continue goto return

syntax match cLabel "case"
syntax match cLabel "default"
syntax match cStatement "break"

syntax match cCaseFold "\(\<case\> .\+\|default\):\(\n\s*<\case\>\)*\_.\{-}break;" transparent fold
