#!/bin/sh

#commands
xprop=`which xprop`
xdotool=`which xdotool`
xte=`which xte`
xwininfo=`which xwininfo`

echo "Click on the window you want to manipulate."
w_id="$(xdotool selectwindow)"


while true; do
    read -p "Which manipulation? (M)inimize (K)ill (S)witch (C)hange_position/move (R)esize 
    > " opt
    case $opt in
        [Mm]* ) $xdotool windowminimize $w_id;;
        [Kk]* ) $xdotool windowkill $w_id; break;;
        [Ss]* ) $xdotool windowactivate $w_id;;
        [Cc]* ) read -p "X value? 
        > " x; read -p "Y value? 
        > " y; $xdotool windowmove $w_id $x $y;;
        [Rr]* ) read -p "Width? i.e. 100%, 20%, 300 
        > " w; read -p "Height? i.e. 100%, 20%, 300
        > " h; $xdotool windowsize $w_id $w $h;;
        * ) echo "Not a valid manipulation.";;     
        
    esac
done
