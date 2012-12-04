# Module1

package Module1; # a class

sub func1 {
    print " func1\n";
}

sub new {
    my $class = shift;
    my $self = {};

    $self->{NAME};
    bless ($self, $class);
    return $self;
}

sub name {
    my $self = shift;

    if (@_) { $self->{NAME} = shift }
    return $self->{NAME};
}

END { }

1;
