" t_XX {{{1

set t_fd= t_fe= " disable xterm-focus-event
set t_TE= t_TI= " disable modifyOtherKeys

" TWEAKS {{{1
" WhatHighlightsIt - check highlight group under the cursor {{{2

function! WhatHighlightsIt() abort
  let [ l, c, n ] = [ line("."), col("."), "name" ]
  echo "hi<"
        \ . synIDattr(synID(l, c, 1), n)             . '> trans<'
        \ . synIDattr(synID(l, c, 0), n)             . "> lo<"
        \ . synIDattr(synIDtrans(synID(l, c, 1)), n) . ">"
endfunction

" Make keyword group contained {{{2

function! KeywordGroupContained(group) abort
  let x = split(execute("syntax list " . a:group), '\n')
  let y = index(map(deepcopy(x), 'v:val =~ ".*links to .*"'), 1)
  if y > 0
    let y = y-1
  endif
  let x = split(join(x[:y]))
  let x = x[index(x, 'xxx')+1:]
  execute "syntax clear ".a:group
  execute "syntax keyword ".a:group." contained ".join(x)
endfunction

" VSetSearch {{{2

function! s:VSetSearch(cmdtype) abort " search for selected text, forwards or backwards
  let temp = @s
  norm! gv"sy
  let @/ = '\V' . substitute(escape(@s, a:cmdtype.'\'), '\n', '\\n', 'g')
  let @s = temp
endfunction

xnoremap # :<C-u>call <SID>VSetSearch('?')<CR>?<C-r>=@/<CR><CR>
xnoremap * :<C-u>call <SID>VSetSearch('/')<CR>/<C-r>=@/<CR><CR>

" HighlightC_PreProcDefines {{{2

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

" PLUGIN CONFIG {{{1
" ALE {{{2

let g:ale_disable_lsp     = 1
let g:ale_echo_msg_format = '[%linter%]: %s'
let g:ale_set_quickfix    = 1
let g:ale_set_signs       = 0

nnoremap <F2> :ALEToggle<CR>
nmap <M-a> <Plug>(ale_detail)

hi! link ALEError    Error
hi! link ALEWarning  WarningMsg

augroup ALE_CONFIG
  au!
  autocmd VimEnter * let g:ale_enabled =
        \ get(g:, "ale_enabled", 0) * empty(filter(getqflist(), 'v:val.valid'))
augroup END

" vim-lsp {{{2

let g:lsp_diagnostics_enabled                = 1
let g:lsp_diagnostics_echo_cursor            = g:lsp_diagnostics_enabled
let g:lsp_diagnostics_highlights_delay       = 0
let g:lsp_diagnostics_signs_enabled          = 0
let g:lsp_document_code_action_signs_enabled = 0

hi! link LspErrorHighlight   Error
hi! link LspWarningHighlight WarningMsg

function! s:lsp_init() abort
  setlocal omnifunc=lsp#complete
  if exists('+tagfunc') | setlocal tagfunc=lsp#tagfunc | endif
  nmap <buffer> gd <plug>(lsp-definition)
  nmap <buffer> gR <Plug>(lsp-rename)
endfunction

augroup LSP
  au!
  autocmd User lsp_buffer_enabled call s:lsp_init()

  if executable('ccls')
    au User lsp_setup call lsp#register_server({
          \   'name': 'ccls',
          \   'cmd': {server_info->['ccls']},
          \   'root_uri': {server_info->lsp#utils#path_to_uri(lsp#utils#find_nearest_parent_file_directory(lsp#utils#get_buffer_path(), 'compile_commands.json'))},
          \   'initialization_options': {
          \     'cache': {'directory': '/tmp/ccls/cache' },
          \     'clang': {'extraArgs': ['--gcc-toolchain=/usr'] },
          \   },
          \   'whitelist': [ 'c', 'cpp', 'objc', 'objcpp', 'cc' ],
          \ })
  endif

  if executable('jdtls')
    au User lsp_setup call lsp#register_server({
          \ 'name': 'eclipse.jdt.ls',
          \ 'cmd': {server_info->['jdtls']},
          \ 'whitelist': [ 'java' ],
          \ })
  endif

  if executable('pyls')
    au User lsp_setup call lsp#register_server({
          \ 'name': 'pyls',
          \ 'cmd': {server_info->['pyls']},
          \ 'whitelist': [ 'python' ],
          \ })
  endif

  if executable('sqls')
    autocmd User lsp_setup call lsp#register_server({
          \ 'name': 'sqls',
          \ 'cmd': {server_info->['sqls']},
          \ 'workspace_config': {
          \   'sqls': {
          \     'connections': [
          \       {
          \         'driver': 'sqlite3',
          \         'dataSourceName': expand($SQLS_SQLITE_DB),
          \       },
          \       {
          \         'driver': 'mysql',
          \         'proto':  'unix',
          \         'user':   expand($SQLS_MYSQL_USER),
          \         'passwd': expand($SQLS_MYSQL_PASSWD),
          \         'path':   '/run/mysqld/mysqld.sock',
          \         'dbName': expand($SQLS_MYSQL_DB),
          \       },
          \     ],
          \   },
          \ },
          \ 'whitelist': [ 'sql' ]
          \ })
  endif

  if executable('texlab')
    au User lsp_setup call lsp#register_server({
          \ 'name': 'TexLab',
          \ 'cmd': {server_info->['texlab']},
          \ 'whitelist': [ 'tex' ],
          \ })
  endif

augroup END

" UltiSnip {{{2

function! UltiSnips_complete(...) abort
  let l:word = matchstr(getline('.'), '\S\+\%'.col('.').'c')
  if !empty(UltiSnips#SnippetsInCurrentScope(1))
    let l:suggestions = map(filter(keys(g:current_ulti_dict_info), 'stridx(v:val, l:word) == 0'),
          \  '{
          \      "word": v:val,
          \      "menu": "  ".get(g:current_ulti_dict_info[v:val], "description", ""),
          \      "dup" : 1
          \   }')
    call complete(col('.') - len(l:word), l:suggestions)
  endif
  return ''
endfunction

inoremap <silent> <C-S-u> <C-r>=UltiSnips_complete()<CR>

" YCM {{{2

let s:BuildYCM_flags = "--clang-completer"

" Build YouCompleteMe - for Plug
function! BuildYCM(info)
    if a:info.status == 'installed' || a:info.force
        execute "!./install.py ".s:BuildYCM_flags
    endif
endfunction

" Build YouCompleteMe
function! BuildYCM_manual()
    execute "!~/.vim/bundle/YouCompleteMe/install.py ".s:BuildYCM_flags
endfunction


" VARIABLES --------------------------------------------------------------------

let g:ycm_add_preview_to_completeopt                 = 0
let g:ycm_always_populate_location_list              = 0
let g:ycm_autoclose_preview_window_after_completion  = 1
let g:ycm_collect_identifiers_from_tags_files        = 1
let g:ycm_complete_in_comments                       = 1
let g:ycm_complete_in_strings                        = 1
let g:ycm_confirm_extra_conf                         = 0
let g:ycm_global_ycm_extra_conf                      = '$HOME/dotfiles/vim/ycm_extra_conf.py'
let g:ycm_key_list_stop_completion                   = ['<C-y>']
let g:ycm_max_num_candidates                         = 20
let g:ycm_min_num_of_chars_for_completion            = 2
let g:ycm_show_diagnostics_ui                        = 0
let g:ycm_use_ultisnips_completer                    = 1

let g:ycm_filetype_blacklist = {
            \ 'infolog': 1,
            \ 'mail': 1,
            \ 'man': 1,
            \ 'notes': 1,
            \ 'pandoc': 1,
            \ 'qf': 1,
            \ 'tagbar': 1,
            \ 'unite': 1,
            \ 'vimwiki': 1,
            \ }

let g:ycm_semantic_triggers = {
            \ 'c'           : ['re!\w', '.', '->', '#'],
            \ 'cpp'         : ['re!\w', '.', '->', '#', '::'],
            \ 'cs'          : ['re!\w', '.'],
            \ 'css'         : ['re!\w', '#', ':', '!'],
            \ 'java'        : ['re!\w', '.'],
            \ 'javascript'  : ['re!\w', '.'],
            \ 'lua'         : ['re!\w', '.', ':'],
            \ 'perl'        : ['re!\w', '->'],
            \ 'php'         : ['re!\w', '->', '::'],
            \ 'python'      : ['re!\w', '.'],
            \ 'snippets'    : ['re!\w'],
            \ 'sql'         : ['re!\w', '.'],
            \ 'vim'         : ['re!\w'],
            \ }
