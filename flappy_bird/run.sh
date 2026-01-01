#!/bin/bash

APP_PATH="./flappy_bird"
TITLE="flappy bird"
COLS=140
LINES=40

if [ ! -x "$APP_PATH" ]; then
    echo "Error: $APP_PATH is not found or not executable"
    exit 1
fi

gnome-terminal \
    --title="$TITLE" \
    --geometry=${COLS}x${LINES} \
    -- bash -c "$APP_PATH"

