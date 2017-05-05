#!/bin/sh

#commands
xprop=`which xprop`
xdotool=`which xdotool`
xte=`which xte`
echo=`which echo`
xwininfo=`which xwininfo`

if [ -n "$xprop" -a -n "$xdotool" -a -n "$xte" ]; then
  #get all windows visible
  
  windows=`$xprop -root | sed -n -e "/_NET_CLIENT_LIST_STACKING(WINDOW): window id #/ {s/.* # \(.*\)/\1/;s/,//g;p}"`
  
  #go through all window ids
  for w_id in $windows; do
    #get class to find window we want
    w_class=`$xprop -id $w_id | sed -n -e "s/^WM_CLASS(STRING).*\"\(.*\)\", \".*\"/\1/ p"`
    
    if [ "$w_class" = "tk" ]; then
      #bring it to fore so we can automate on it
      $xdotool windowactivate $w_id

      TOP_LEFT_X=`xwininfo -all -int -id $w_id|grep Absolute |grep X |cut -d ':' -f2 |sed 's/ //g'`
      TOP_LEFT_Y=`xwininfo -all -int -id $w_id|grep Absolute |grep Y |cut -d ':' -f2 |sed 's/ //g'`
      $xdotool mousemove $TOP_LEFT_X $TOP_LEFT_Y
      WIDTH=`xwininfo -all -int -id $w_id|grep Width|cut -d ':' -f2 |cut -d ' ' -f2`
      HEIGHT=`xwininfo -all -int -id $w_id|grep Height|cut -d ':' -f2 |cut -d ' ' -f2`
      CENTER_X=`echo $WIDTH/2|bc`
      CENTER_Y=`echo $HEIGHT/2|bc`
      $xdotool mousemove_relative $CENTER_X `echo $CENTER_Y+$CENTER_Y/2|bc`
      $xdotool click 1
      $xdotool type 'A ROBOT WAS HERE'
    fi
  done
  
  
fi