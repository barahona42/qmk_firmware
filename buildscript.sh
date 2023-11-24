QMK_PATH=/Users/rbarahona/development/repos/personal/qmk_firmware
ACTION="$1"
KM=barahona42

function find_kb(){
    case $1 in
        anc|an_c)
            kb=cannonkeys/an_c
        ;;
        ortho60)
            kb=cannonkeys/ortho60v2
        ;;
        gmmk2_65)
            kb=gmmk/gmmk2/p65/ansi
        ;;
        gmmk2_96)
            kb=gmmk/gmmk2/p96/ansi
        ;;
        *)
            echo "no kb value matched"
            exit 1
        ;;
    esac
    echo "$kb"
}

case $ACTION in
    list)
        find $QMK_PATH -type d -name barahona42 | sed -r 's/.*keyboards\/|\/keymaps\/.*//g'
    ;;
    compile)
        kb=$(find_kb $2)
        echo "compiling $kb"
        qmk compile -kb $kb -km $KM
    ;;
    open)
        kb=$(find_kb $2)
        echo $QMK_PATH/keyboards/$kb
        # for file in $(find $QMK_PATH -type d -name barahona42); do
        #     echo "$file"
        # done
        # find $QMK_PATH -type d -name barahona42
    ;;
esac
