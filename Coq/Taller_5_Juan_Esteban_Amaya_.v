(* Taller 5 =( *)

Section LPPO_1.
Variable D: Set.
Variable c d e: D.
Variable P Q T: D -> Prop.

(* Punto 1 *)
Theorem pred_008 : ~( forall x, P x ) -> ~ forall x, P x /\ Q x.
Proof.
intro.
intro.
destruct H.
apply H0.
Qed.

(* Punto 2 *)
Theorem pred_013 : ( exists x, P x \/ Q x ) -> ( forall x, ~Q x ) -> exists x, P x.
Proof.
intro.
intro.
destruct H.
exists x.
destruct H.
assumption.
apply H0 in H.
contradiction.
Qed.

(* Punto 3 *)
Theorem pred_025 : ~( forall x, P x /\ Q x ) /\ ( forall x, P x ) -> ~forall x, Q x.
Proof.
intro.
intro.
destruct H.
destruct H.
intro.
split.
apply H1.
apply H0.
Qed.

(* Punto 4 *)
Theorem pred_035 : (forall y, Q y -> ~exists x, P x) /\ (forall x, P x) -> forall y, ~Q y.
Proof.
intro.
intro.
intro.
destruct H.
apply H in H0.
apply H0.
exists y.
destruct H0.
exists y.
apply H1.
Qed.

(* Punto 5 *)
Theorem pred_067 : ( forall x, ~P x ) -> ~exists x, P x.
Proof.
intro.
intro.
destruct H0.
apply H in H0.
assumption.
Qed.
End LPPO_1.

Section LPPO_2.
Variable A : Set.
Variables (P Q : A -> Prop)
(R : A -> A -> Prop).

(* Punto 6 *)
Lemma forall_imp_dist : ( forall x:A, P x -> Q x ) ->
( forall x:A, P x ) ->
  forall x: A, Q x.
Proof.
intro.
intro.
intro.
apply H.
apply H0.
Qed.

(* Punto 7 *)
Lemma forall_perm : ( forall x y:A, R x y ) -> forall y x, R x y.
Proof.
intro.
intro.
intro.
apply H.
Qed.

(* Punto 8 *)
Lemma forall_delta : ( forall x y:A, R x y ) -> forall x, R x x.
Proof.
intro.
intro.
apply H.
Qed.

(* Punto 9 *)
Lemma exists_or_dist : ( exists x: A, P x \/ Q x ) <->
( exists x, P x ) \/ ( exists x , Q x ).
Proof.
split.
intro.
destruct H.
destruct H.
left.
exists x.
assumption.
right.
exists x.
assumption.
intro.
destruct H.
destruct H.
exists x.
left.
assumption.
destruct H.
exists x.
right.
assumption.
Qed.

(* Punto 10 *)
Lemma exists_imp_dist : ( exists x: A, P x -> Q x ) ->
( forall x:A, P x ) ->
  exists x:A, Q x.
Proof.
intro.
intro.
destruct H.
exists x.
apply H.
apply H0.
Qed.

(* Punto 11 *)
Lemma not_empty_forall_exists : forall a:A,
( forall x:A, P x ) ->
  exists x:A, P x.
Proof.
intro.
intro.
exists a.
apply H.
Qed.

(* Punto 12 *)
Lemma not_ex_forall_not : ~( exists x:A, P x ) <-> forall x:A, ~P x.
Proof.
split.
intro.
intro.
intro.
destruct H.
exists x.
assumption.
intro.
intro.
destruct H0.
unfold not in H.
apply H in H0.
assumption.
Qed.
End LPPO_2.

(* Punto 13 *)
(* D: Es el conjunto de coyotes.
   A: Es el conjunto de correcaminos. 
   P( x, y ): Un coyote x, persigue a un correcaminos y.
   Q( x ): Un correcaminos x hace beep-beep.
   R( x ): Un correcaminos x es astuto.
   S( x, y ): Un coyote x es capaz de atrapar al correcaminos y.
   T( x ): Un coyote x esta frustrado.
*)
Section Punto13.
Variable D A: Set.
Variable P S: D -> A -> Prop.
Variable Q R: A -> Prop.
Variable T: D -> Prop.
Hypothesis H1: forall x: D, ( exists y: A, P x y ).
Hypothesis H2: forall x: A, ( Q x -> R x ).
Hypothesis H3: ~ ( exists x: D, exists y: A, ( S x y /\ R y ) ).
Hypothesis H4: forall x: D, ~ ( exists y: A, S x y ) -> ( T x ).
Theorem UnicornioEspacial: ( forall y: A, Q y ) -> ( forall x: D, T x ). 
Proof.
intro.
intro.
apply H4.
unfold not in H4 .
intro.
destruct H0.
assert ( H5 := H x0 ).
assert ( H6 := H2 x0 ).
destruct H3.
exists x.
exists x0.
split.
assumption.
apply H2.
assumption.
Qed.
End Punto13.

(* Punto 14 *)
(* D: Es el conjunto de niños.
   A: Es el conjunto de brujas. 
   P( x, y ): niño x, ve bruja y.
   Q( x ): Bruja x tiene gato negro.
   R( x ): Bruja x tiene sombrero punteagudo.
   S( x ): Bruja x buena.
   T( x ): Bruja x mala.
   U( x ): Niño x recibe dulces.
*)

Section Punto14.
Variable D A: Set.
Variable P: D -> A -> Prop.
Variable Q R S T: A -> Prop.
Variable U: D -> Prop.
Hypothesis H1: forall x: D, exists y: A, P x y.
Hypothesis H2: forall x: A, ~( Q x /\ R x ).
Hypothesis H3: forall x: A, ( S x ) \/ ( T x ).
Hypothesis H4: forall x: D, forall y: A,( P x y /\ S y ) -> U x.
Hypothesis H5: forall x: A, ( T x ) -> ( Q x ).
Theorem UnicornioMeteorico: forall x: D, ( forall y: A,  P x y /\ R y )  -> U x. 
Proof.
intro.
intro.
assert ( H1 := H1 x ).
destruct H1.
assert ( H8 := H5 x0 ).
assert ( H9 := H4 x ).
assert ( H10 := H9 x0 ).
apply H10.
split.
assumption.
assert ( H3 := H3 x0 ).
destruct H3.
assumption.
assert ( H2 := H2 x0 ).
assert ( H5 := H5 x0 ).
destruct H2.
split.
apply H5.
assumption.
apply H.
Qed.
End Punto14.

Section Punto15.

(*
   D: Es el conjunto de personas.
   A: Es el conjunto de renos. 
   P( x ): x es un muchacho.
   Q( x ): x ama a santa.
   R( x, y ): Una persona x ama a cualquier reno y.
   S( x ): x tiene la nariz roja.
   T( x ): x es raro.
   U( x ): x es un payazo.
   W: Scrooge.

*)

Variables D A: Set.
Variables P Q: D -> Prop.
Variables R: D -> A -> Prop.
Variables S T U: A -> Prop.
Variables W: D.
Hypothesis H1: forall x: D, ( P x ) -> ( Q x).
Hypothesis H2: forall x: D, forall y: A, ( Q x ) -> ( R x y ).
Hypothesis H3: exists x: A, S x.
Hypothesis H4: forall x: A, ( S x ) -> ( T x \/ U x ).
Hypothesis H5: forall x:A, ~U x.
Hypothesis H6: forall x: A, ( T x ) -> ~(R W x).
Theorem UnicornioGalactico: ~ ( P W ).
Proof.
intro.
specialize H1 with W.
destruct H3.
assert ( H6 := H6 x ).
assert ( H2 := H2 W ).
assert ( H5 := H5 x ).
assert ( H4 := H4 x ).
assert ( H2 := H2 x ).
apply H1 in H.
apply H2 in H.
apply H4 in H0.
destruct H0.
apply H6 in H0.
contradiction.
contradiction.
Qed.
End Punto15.