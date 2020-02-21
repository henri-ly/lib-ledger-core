#!/usr/bin/env bash

echo "========> Install basic config"
brew update
brew install wget

echo "========> Install Java"
brew cask install java8
echo "========> Java Installed"
brew cask info java8
echo "$(/usr/libexec/java_home -v 1.8)"
export JAVA_HOME="$(/usr/libexec/java_home -v 1.8)"

echo "========> Install C++ dependencies"
brew install cmake

echo "========> Install PostgreSQL"
brew install postgresql

echo "========> Install Sqlite"
brew install sqlite



