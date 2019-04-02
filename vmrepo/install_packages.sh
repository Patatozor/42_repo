#!/bin/sh
apt update
apt upgrade -y
apt install openssh-server -y
apt install sudo -y
apt install postfix -y
apt install git -y
apt install apache2
