#!/bin/bash

black='\E[30;47m'
red='\E[31;47m'
green='\E[32;47m'

yello='\E[33;47m'
blue='\E[34;47m'



magenta='\E[35;47m'
cyan='\E[36;47m'
white='\E[37;47m'



alias Reset="tput sgr0"
cecho(){

	local default_msg="no message"
	message=${1:-$default_msg}
	color=${2:-$black}
	echo -e "$color"
	echo "$message"
	Reset
	return
}

cecho "feeling blue" $blue

cecho "feeling yellow" $yellow
cecho "feeling cyan" $cyan
cecho "feeling red" $red
cecho "feeling black" $black
cecho "feeling green" $green

