#! /bin/bash

# Shell script for timer which plays random tunes in a directory
# The default timer time is 20 minutes which can be changed by timer_dur variables
# The default player for the audio or video is celluloid
# This script runs the process in the background
# Date: 24-07-2020

timer_dur_hour=0
timer_dur_min=20
timer_dur_sec=0

# Uncomment the following lines to have a timer with variable length

#read -p "Hours: " timer_dur_hour
#read -p "Minutes: " timer_dur_min
#read -p "Seconds: " timer_dur_sec

lgfile=$(ls | grep "log_timer.txt")

if [[ ! -e $lgfile ]]; then
    touch log_timer.txt
fi

echo "The timer is starting!"

c_date=$(date | awk -F' ' {'print $2" "$3" "$4'})

s_date=$(grep "Start time:" log_timer.txt | tail -n 1 | awk -F' ' {'print $4" "$5" "$6'})

if [[ $s_date == $c_date ]]; then
    count=$(grep "count" log_timer.txt | tail -n 1 | sed {s/^.*count=//g})
    count=$(( count + 1 ))
    echo "Start time: $(date) | count=${count}" >> log_timer.txt
else
    echo "" >> log_timer.txt
    echo "Start time: $(date) | count=0" >> log_timer.txt
fi


timer_tune=$(ls | grep -E "^*mp3$|^*wav$|^*m4a$" | shuf -n 1)

sleep ${timer_dur_hour}h ${timer_dur_min}m ${timer_dur_sec}s && celluloid $timer_tune &

