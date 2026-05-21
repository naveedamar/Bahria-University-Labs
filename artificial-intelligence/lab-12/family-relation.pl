% Family Relationship Checker

mother(alishba, hafeez).
father(kamran, hafeez).

parent(X, Y) :- mother(X, Y).
parent(X, Y) :- father(X, Y).

:- initialization(main).

main :-
    ( parent(kamran, hafeez) ->
        write(true), nl
    ;
        write(false), nl
    ).