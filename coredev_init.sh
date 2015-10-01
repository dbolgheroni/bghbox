#!/bin/sh

HOST=$1
COREDEV_FILES="$HOME/.pentadactyl $HOME/.ssh/config $HOME/.Xdefaults $HOME/.Xmodmap $HOME/.Xresources $HOME/.cvsrc $HOME/.gitconfig $HOME/.gtkrc-2.0 $HOME/.gvimrc $HOME/.inputrc $HOME/.mailcap $HOME/.mailrc $HOME/.login $HOME/.profile $HOME/.pentadactylrc $HOME/.signature $HOME/.signature-gmail $HOME/.spectrwm.conf $HOME/.sqliterc $HOME/.tmux.conf $HOME/.vimrc $HOME/.xinitrc $HOME/.xsession $HOME/bin"

if [ -z $HOST ]; then
    echo "$0: no host specified"
    exit 1
fi

rsync --delete -rlptgoDv $COREDEV_FILES $HOST:~
