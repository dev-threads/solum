#!/usr/bin/env bash

echo "Setting up useful Git aliases..." &&

# General aliases that could be global
git config alias.pullall '!bash -c "git pull && git submodule update --init"' &&
git config alias.prepush 'log --graph --stat origin/master..' &&

# Staging aliases
stage_disabled="VTK no longer uses the topic stage. Please use GitHub." &&
git config alias.stage-cmd '!sh -c "echo '"${stage_disabled}"'"' &&
git config alias.stage-push '!sh -c "echo '"${stage_disabled}"'"' &&
git config alias.stage-branch '!sh -c "echo '"${stage_disabled}"'"' &&
git config alias.stage-merge '!sh -c "echo '"${stage_disabled}"'"' &&

# Alias to push the current topic branch to GitHub
git config alias.github-push '!bash Utilities/GitSetup/git-github-push' &&

true
