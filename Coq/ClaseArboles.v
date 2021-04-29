Inductive NOMBRE : Set :=
  |elem1 : NOMBRE
  |elem2 : NOMBRE
  |constructora : NOMBRE -> NOMBRE
  |constructora2 : NOMBRE -> NOMBRE -> NOMBRE. (* Resive dos y retorna 1 *)

Inductive NAT : Set :=
  |O : NAT            (* Caso base *)
  |Suc : NAT -> NAT.  (* Función constructora *)

Check O.
Check NAT.
Check Suc O.

Definition P ( n: NAT ): NAT :=
  match n with 
    |O => O
    |Suc n1 => n1
  end.

Definition UNO := Suc O.
Definition DOS := Suc UNO.
Definition TRES := Suc DOS.

Compute P ( UNO ).
Compute P ( DOS ).
Compute P ( TRES ).

Fixpoint SUMA( a b : NAT ) : NAT :=
  match a with 
    |O => b
    |Suc a1 => Suc( SUMA a1 b )
  end.

Compute SUMA DOS UNO.

Fixpoint PAR( n : NAT ) : bool :=
  match n with
    |O => true
    |Suc n1 => match n1 with
                |O => false
                |Suc n2 => PAR n2
               end
      end.

Compute PAR DOS.

Inductive ArbolB := Set 
  |vacio => AbolB
  |cons => Arbolb -> ArbolB -> ArbolB
  