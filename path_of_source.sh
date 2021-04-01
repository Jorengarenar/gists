if [ -n "$BASH_VERSION" ]; then
    t="$BASH_SOURCE"
elif [ -n "$ZSH_VERSION" ]; then
    t="${(%):-%x}"
elif [ -n "$TMOUT" ]; then
    t="${.sh.file}"
elif [ -x "$(command -v lsof)" ]; then
    t="$(lsof -p $$ -Fn0 | tail -1)"; t="${t#n}"
fi

t="$(realpath $t))"