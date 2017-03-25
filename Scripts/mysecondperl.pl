#!/usr/bin/perl -w
use strict;
use warnings;

while(my $line = <STDIN>){
	#print "I have seen $line";
	if($line =~ /^\?.*[0-9]/){
		#my $last_value = pop @processed;
		my @processed = split(/\b/, $line);
		print $processed[1], "\n";
		my @second_process = split(/_/, $processed[1]);
		my @first_value = shift @second_process;
		foreach my $word (@second_process){
			print $word, " ";
		}
		print "\n";
	}
}
