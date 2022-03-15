#!/bin/bash 


. ./config.sh


command="rm -rf ${build_dir}*"

echo -e "/!\\ Cleaning with command: '${command}'"
echo -e "     proceed? [y/N]"
    
read opt
case $opt in
[yY]) 			
    echo "[*] Cleaning ..."
    eval "${command}"
    echo "Done"
    ;;				
*)	echo "Aborted"
esac				


