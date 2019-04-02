#!/bin/sh
echo "Type yes then ENTER when asked"
cat ~/.ssh.id_rsa.pub | ssh root@10.13.14.1 -p 9999 "mkdir -p ~/.ssh && touch ~/.ssh/authorized_keys && chmod -R go = ~/.ssh && cat >> ~/.ssh/authorized_keys"
chown -R default_user:default ~/.ssh
sed -i '/^PermitRootLogin/s/yes/no/' /etc/ssh/sshd_config
sed -i '/^PermitAuthentication/s/yes/no/' /etc/ssh/sshd_config
systemctl restart ssh
