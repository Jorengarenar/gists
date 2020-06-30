#ifndef TERM_ESC_SEQ_H_
#define TERM_ESC_SEQ_H_

#ifdef linux
    #define RESET           "\033[0m"

    #define BOLD            "\033[1m"

    #define ITALIC          "\033[3m"
    #define ITALIC_OFF      "\033[23m"

    #define UNDERLINE       "\033[4m"
    #define UNDERLINE_OFF   "\033[24m"

    #define BLINK_SLOW      "\033[5m"
    #define BLINK_RAPID     "\033[6m"
    #define BLINK_OFF       "\033[6m"

    #define INVERSE         "\033[7m"
    #define INVERSE_OFF     "\033[27m"

    #define CROSSED_OUT     "\033[9m"
    #define CROSSED_OUT_OFF "\033[29m"

    #define FG_BLACK        "\033[30m"
    #define FG_RED          "\033[31m"
    #define FG_GREEN        "\033[32m"
    #define FG_YELLOW       "\033[33m"
    #define FG_BLUE         "\033[34m"
    #define FG_MAGENTA      "\033[35m"
    #define FG_CYAN         "\033[36m"
    #define FG_WHITE        "\033[37m"
    #define FG_GREY         "\033[90m"

    #define BG_BLACK        "\033[40m"
    #define BG_RED          "\033[41m"
    #define BG_GREEN        "\033[42m"
    #define BG_YELLOW       "\033[43m"
    #define BG_BLUE         "\033[44m"
    #define BG_MAGENTA      "\033[45m"
    #define BG_CYAN         "\033[46m"
    #define BG_WHITE        "\033[47m"

#else
    #define RESET           ""
    #define BOLD            ""
    #define ITALIC          ""
    #define ITALIC_OFF      ""
    #define UNDERLINE       ""
    #define UNDERLINE_OFF   ""
    #define BLINK_SLOW      ""
    #define BLINK_RAPID     ""
    #define BLINK_OFF       ""
    #define INVERSE         ""
    #define INVERSE_OFF     ""
    #define CROSSED_OUT     ""
    #define CROSSED_OUT_OFF ""
    #define FG_BLACK        ""
    #define FG_RED          ""
    #define FG_GREEN        ""
    #define FG_YELLOW       ""
    #define FG_BLUE         ""
    #define FG_MAGENTA      ""
    #define FG_CYAN         ""
    #define FG_WHITE        ""
    #define FG_GREY         ""
    #define BG_BLACK        ""
    #define BG_RED          ""
    #define BG_GREEN        ""
    #define BG_YELLOW       ""
    #define BG_BLUE         ""
    #define BG_MAGENTA      ""
    #define BG_CYAN         ""
    #define BG_WHITE        ""

#endif

#endif