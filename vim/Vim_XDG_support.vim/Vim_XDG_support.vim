" Put this in your `vimrc` (preferably somewhere at the beginning):

" XDG support    (`set rtp^=$VIMDOTDIR` is in $VIMINIT)
set backupdir=$XDG_DATA_HOME/vim/backup
set directory=$XDG_CACHE_HOME/vim/swap
set packpath^=$XDG_DATA_HOME/vim
set runtimepath+=$VIMDOTDIR/after
set runtimepath+=$XDG_DATA_HOME/vim
set undodir=$XDG_CACHE_HOME/vim/undo
set viminfo+=n$XDG_CACHE_HOME/vim/viminfo

" Create `backup` and `spell` dir
call mkdir(&backupdir, 'p')
call mkdir($XDG_DATA_HOME."/vim/spell", 'p')