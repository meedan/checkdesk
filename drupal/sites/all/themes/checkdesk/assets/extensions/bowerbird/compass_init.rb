#!/usr/bin/env ruby

require 'compass'

base_directory = File.join(File.dirname(__FILE__), '..', 'stylesheets')
Compass::Frameworks.register('bowerbird', :path => base_directory)