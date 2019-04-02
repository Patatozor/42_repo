#!/bin/sh
ssh root:root@10.13.14.1
adduser default_user
sudo adduser default_user
usermod -aG sudo default_user
