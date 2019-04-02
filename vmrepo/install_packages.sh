#!/bin/sh
apt update
apt upgrade -y
apt-get install openssh-server -y
apt-get install sudo -y
apt-get install postfix -y
apt-get install git -y
