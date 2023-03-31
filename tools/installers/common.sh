#!/bin/bash

# If OUTPUT has not been defined earlier, set it to /dev/null
OUTPUT=${OUTPUT-/dev/null}

if [[ "$OSTYPE" == "darwin"* ]]; then
    terminal_prefix="\x1B"
else
    terminal_prefix="\e"
fi
fail_hilight="${terminal_prefix}[41m" # red background, green letters
pass_hilight="${terminal_prefix}[30;42m" # green background, black letters
nocolor="${terminal_prefix}[0m"

# log_error: output function to echo message in red for mac and linux.
log_error(){
    echo -e "${fail_hilight}[FAIL] $* ${nocolor}" >&2
}

# log_success: output function to echo message in green for mac and linux.
log_success(){
    echo -e "${pass_hilight}[PASS]${nocolor} $*" >&2
}

# on_exit: helper function for all scripts that source common.sh
on_exit(){
    caller_script=$(basename `caller | awk '{print $NF}'`)
    rc=$*
    if [[ $rc -ne 0 ]]; then
        log_error "${caller_script} returned non-zero return-code: ${rc}"
        exit $rc
    else
        log_success "${caller_script} completed successfully."
    fi
}
