(* Punto 1 *)
Definition Cuadrado( num: nat ): nat :=
num * num.
Compute Cuadrado 5.

Definition Cubo( num: nat ): nat :=
num * num * num.
Compute Cubo 3.

(* Punto 2 *)
Definition Constante := 5 * 5.

Definition SumaConstante( num: nat ) : nat :=
num + Constante.
Compute SumaConstante 2.

(* Otra Opción *)
Definition Const( num: nat ): nat :=
num * num.

Definition SumaConst( num1 num2: nat ) :=
num1 + num2.
Compute SumaConst( Const 5 ) 2.

(* Punto 3 *)
Definition SumaCubos( num1 num2: nat ): nat :=
( num1 * num1 * num1 ) + ( num2 * num2 * num2 ).
Compute SumaCubos 2 3.

(* Punto 4 *)
Definition Cuatro( num1 num2 num3 num4: nat ): nat :=
( num1 + num2 + num3 + num4 )*( num1 * num2 * num3 * num4 ).

Compute Cuatro 1 2 3 4.
 
(* Punto 5 *) 
Search nat.
Search bool.
Compute Nat.double.
Compute Nat.div2.
Compute Nat.leb.

Print nat.
Print bool.
Print Nat.double. (* Retorna el doble de un nat *)
Print Nat.div2. (* Retorna la division entera entre 2 de un nat*)
Print Nat.leb. (* es un <= que compara dos nat y retorna un bool dependiendo el resultado *)

(* Punto 6 *)
Definition esPar( num: nat ) :=
Nat.leb num ( ( Nat.div2 num ) * Nat.double 1 ).
Compute esPar 7 .

(* Punto 7 *)
Definition funcion( num: nat*nat ): nat*nat :=
( fst num , snd num ).

Definition iter2p( f: nat*nat->nat*nat )( p: nat*nat ): nat*nat :=
f( f ( p ) ).
Compute (iter2p (fun p => (snd p, fst p)) (1, 2),
iter2p (fun p => (fst p + 1, snd p + fst p + 1)) (0,0)).

(* Punto 8 *)
Definition composFun ( f: ( nat->nat ) )( g: ( nat -> nat ) ) :=
fun funcion => f( g funcion ).

(* Punto 9 *)
Definition Suma( num: nat*nat ): nat :=
fst num + snd num.
Compute Suma( 2, 3 ).

(* punto 10 *)
Definition t := ( 3, 2, 1 ).
Compute fst t.
Compute fst ( fst t).
Compute snd t.

Definition Trio( num: nat*nat*nat ): nat :=
fst( fst num ) * fst( fst num ) * fst( fst num ) + snd( fst num ) * snd( fst num ) * snd( fst num ) +( snd num * snd num * snd num ). 
Compute Trio( 1, 2, 3 ).

(* Punto 11 *)
Definition Impar ( num: nat ): nat :=
match esPar( num ) with
  |true => Nat.double num
  |false => num + 1
end.

Compute Impar 2.

(* Punto 12 *)
Definition SumaMulti2 ( num: nat*nat ): nat*nat :=
( fst num + snd num, fst num * snd num ).
Compute SumaMulti2( 1,2 ).

(* Punto 13 *)
Definition fun2( f: nat->nat->nat )( g: nat-> nat )( num: nat * nat ): nat*nat :=
( g( snd num ), f( snd num )(fst num ) ).

(* Punto 14 *)
Definition Funcion( funcion: nat->nat )( num: nat*nat ): nat :=
  match Nat.leb ( fst num )( snd num ) with
    |false => funcion ( fst num - snd num )
    |true => funcion ( snd num + 1 )
end.

(* Punto 15 *)
Inductive LogicaProposicional : Type :=
  |p : LogicaProposicional
  |q : LogicaProposicional
  |r : LogicaProposicional.

Check p.
Check q.
Check r.