#!/usr/bin/perl -w
#
# Copyright (c) 2012, Daniel Bolgheroni. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
# 
#   1. Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#
#   2. Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in
#      the documentation and/or other materials provided with the
#      distribution.
# 
# THIS SOFTWARE IS PROVIDED BY DANIEL BOLGHERONI ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DANIEL BOLGHERONI OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# vcf2abook
# =========
#
# WHAT
#   convert exported Google Contacts to abook format
#
# BUGS
#   probably many, not addressed, but worked for my contacts
#
# CAVEATS
#   when more than 1 number is available with the same category (e.g.
#   cell), only the last one will be kept
#
# HOW TO USE
#   - export your data from Google Contacts using vCard format
#   - run this in the same directory
#   - redirect to a file to abook can use it

use strict;
use MIME::QuotedPrint;

my (@contacts, $i, $j, $k, $nemail, $ntel, $nrec, $name, @teln, @email);

open(CONTACTS, "contacts.vcf") ||
    die "$0: can't open contacts.vcf\n";

print "# abook addressbook file\n\n";

print "[format]\n";
print "program=abook\n";
print "version=0.5.6\n\n";

$i = -1;
while (<CONTACTS>) {
    if (/^FN/) {
        # initialize a new record
        $i++;

        $j = 0; # reset var with a new record
        $k = 0; # reset var with a new record 

        s/FN://; 
        s/FN;CHARSET=UTF-8;ENCODING=QUOTED-PRINTABLE//;
        $contacts[$i]{name} = decode_qp($_);
    }

    if (/^EMAIL/) {
        s/.*://;
        s/\r//g; # remove carriage return
        $contacts[$i]{email}[$j] = $_;

        $j++;
    }

    if (/^TEL/) {
        if (/HOME/) {
            $contacts[$i]{teln}[$k]{type} = "phone";
        } elsif (/CELL/) {
            $contacts[$i]{teln}[$k]{type} = "mobile";
        } elsif (/WORK/) {
            $contacts[$i]{teln}[$k]{type} = "workphone";
        } else {
            $contacts[$i]{teln}[$k]{type} = “other”;
        }

        s/.*://;
        $contacts[$i]{teln}[$k]{number} = $_;

        $k++;
    }
}

# starts in 0 (zero)
$nrec = $i + 1; 
for ($i = 0; $i < $nrec; $i++) {
    print "\n[$i]\n";

    # print name
    print "name=$contacts[$i]{name}";

    # print emails
    if (defined(@{ $contacts[$i]{email} })) {
        chomp @{ $contacts[$i]{email} };
        $nemail = @{ $contacts[$i]{email} };

        print "email=";
        for ($j = 0; $j < $nemail; $j++) {
            print "$contacts[$i]{email}[$j],";
        }

        print "\n";
    }

    # print tels
    if (defined(@{ $contacts[$i]{teln} })) {
        $ntel = @{ $contacts[$i]{teln} };

        for ($k = 0; $k < $ntel; $k++) {
            print "$contacts[$i]{teln}[$k]{type}=";
            print "$contacts[$i]{teln}[$k]{number}";
        }
    }
}
