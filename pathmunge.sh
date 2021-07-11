pathmunge() {
    after=0
    sep=":"

    while getopts as: option; do
        case $option in
            a) after=1       ;;
            s) sep="$OPTARG" ;;
        esac
    done

    shift $(($OPTIND - 1))

    if [ -z "$2" ]; then
        var='PATH'
        new="$1"
    else
        var="$1"
        new="$2"
    fi

    if ! echo "${!var}" | grep -Eq '(^|'"$sep)$new("'$|'"$sep)" ; then
        if [ -z "${!var}" ]; then
            export ${var}="$new"
        elif [ "$after" = "0" ]; then
            export ${var}="$new$sep${!var}"
        else
            export ${var}="${!var}$sep$new"
        fi
    fi

    unset after sep option OPTIND OPTARG
}
