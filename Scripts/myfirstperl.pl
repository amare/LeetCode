#!/usr/bin/perl -w
use strict;
use warnings;

my @files = @ARGV;
open("file", "$ARGV[0]") or die("can not open the file!\n$!");
while(my $line = <file>){
	if($line =~ /(.*)\//){
		my @firstprocess = split(/\b|_/, $line); 
		print $firstprocess[2], " ", $firstprocess[3], "\n";
	}
}
close("file");
