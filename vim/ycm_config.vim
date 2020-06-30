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