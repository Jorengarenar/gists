function! s:VSetSearch(cmdtype) abort " search for selected text, forwards or backwards
  let temp = @s
  norm! gv"sy
  let @/ = '\V' . substitute(escape(@s, a:cmdtype.'\'), '\n', '\\n', 'g')
  let @s = temp
endfunction

xnoremap # :<C-u>call <SID>VSetSearch('?')<CR>?<C-r>=@/<CR><CR>
xnoremap * :<C-u>call <SID>VSetSearch('/')<CR>/<C-r>=@/<CR><CR>
