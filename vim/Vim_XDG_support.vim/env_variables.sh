# Put this in ~/.profile (in exactly the same order):

# And don't forget to set XDG_CONFIG_HOME, XDG_DATA_HOME and XDG_CACHE_HOME !

export VIMDOTDIR="$XDG_CONFIG_HOME/vim" # helper variable, not necessary but very handy
export VIMINIT='set rtp^=$VIMDOTDIR | let $MYVIMRC="$VIMDOTDIR/vimrc" | source $MYVIMRC'