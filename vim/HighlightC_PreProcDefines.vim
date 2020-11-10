function! s:HighlightC_PreProcDefines()
    syntax clear C_PreProcDefine
    for line in getline('1','$')
        if line =~ '^\s*#\s*define\s\+'
            execute 'syntax keyword C_PreProcDefine '.substitute(line, '^\s*#\s*define\s\+\(\k\+\).*$', '\1', '')
        endif
    endfor
endfunction

" C/C++ preprocessor defined macros
autocmd filetype c,cpp autocmd VimEnter,InsertEnter,InsertLeave * call <SID>HighlightC_PreProcDefines()
