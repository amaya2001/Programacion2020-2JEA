(* Taller 3 *)
Section LP1.
Variables P Q R S T : Prop.

(* Punto 1 *)
Lemma weak_pierce : ((((P -> Q) -> P) -> P) -> Q) -> Q.
Proof.
intros.
apply H.
intro.
apply H0.
intro.
apply H.
intro.
assumption.
Qed.

(* Punto 2 *)
Lemma then_bsc : (P -> Q) -> (Q -> R) -> P -> R.
Proof.
intros.
apply H0.
apply H.
assumption.
Qed.

(* Punto 3 *)
Lemma contraposition : (P -> Q) -> (~Q -> ~P).
Proof.
intros.
unfold not.
intro.
unfold not in H0.
apply H0.
apply H.
assumption.
Qed.


(* Punto 4 *)
Lemma contraposition' : (~P -> ~Q) <-> (~~Q -> ~~P).
Proof.
split.
intro.
intro.
intro.
apply H0.
intro.
apply H.
apply H1.
apply H2.
intros.
intro.
apply H.
intro.
apply H2.
apply H1.
assumption.
Qed.

(* Punto 5 *)
Lemma impl_compl : (P <-> Q) -> (Q <-> R) -> (P <-> R).
Proof.
split.
intro.
apply H0.
apply H.
apply H1.
intro.
apply H0 in H1.
apply H in H1.
assumption.
Qed.

(* Punto 6 *)
Lemma then_ext : (P -> Q) -> (P -> R) -> (Q -> R -> S) -> P -> S.
Proof.
intros.
apply H1.
apply H.
apply H2.
apply H0.
assumption.
Qed.

(* Punto 7 *)
Lemma and_assoc : P /\ (Q /\ R) -> (P /\ Q) /\ R.
Proof.
intros.
split.
split.
apply H.
apply H.
apply H.
Qed.

(* Punto 8 *)
Lemma and_imp_dist : (P -> Q) /\ (R -> S) -> P /\ R -> Q /\ S.
Proof.
intros.
split.
apply H.
apply H0.
apply H.
apply H0.
Qed.

(* Punto 9 *)
Lemma or_and_not : (P \/ Q) /\ ~P -> Q.
Proof.
intros.
destruct H.
destruct H.
contradiction.
assumption.
Qed.

(* Punto 10 *)
Lemma not_contrad : ~(P /\ ~P).
Proof.
intro.
destruct H.
contradiction.
Qed.

(* Punto 11 *)
Lemma De_morgan_1 : ~(P \/ Q) -> ~P /\ ~Q.
Proof.
intro.
split.
intro.
apply H.
left.
apply H0.
intro.
apply H.
right.
assumption.
Qed.

(* Punto 12 *)
Lemma De_morgan_2 : ~P /\ ~Q -> ~(P \/ Q).
Proof.
intro.
intro.
apply H.
destruct H.
destruct H0.
contradiction.
assumption.
Qed.

(* Punto 13 *)
Lemma De_morgan_3 : ~P \/ ~Q -> ~(P /\ Q).
Proof.
intro.
intro.
destruct H.
destruct H0.
unfold not in H.
apply H.
contradiction.
destruct H.
destruct H0.
assumption.
Qed.

(* Punto 14 *)
Lemma b_mix : P \/ (Q /\ R) <-> (P \/ Q) /\ (P \/ R).
Proof.
split.
intro.
split.
destruct H.
left.
apply H.
destruct H.
right.
apply H.
destruct H.
left.
apply H.
destruct H.
right.
apply H0.
intros.
destruct H.
destruct H0.
left.
apply H0.
destruct H.
left.
apply H.
right.
split.
apply H.
assumption.
Qed.
End LP1.

(* Punto 15 *)
Section S0.
Variables P Q : Prop.

Hypothesis H0 : P -> Q.
Hypothesis H1 : ~P -> Q.
Lemma weak_exm : ~~Q.
Proof.
intro.
apply H.
apply H1.
intro.
apply H.
apply H0.
assumption.
Qed.
End S0.

(* Punto 16 *)
(* P -> Yo aprobaré logica, Q -> Si Dios quiere, R -> Yo estudio, S -> Yo hago todos los ejercicios *)
Section S1.
Variables P Q R S: Prop.

Hypothesis H0 : Q -> P.
Hypothesis H1 : P <->( R /\ S ).
Lemma unicornio : ~S ->( ~Q /\ ~P ). 
Proof.
intro.
destruct H1.
split.
intro.
apply H.
destruct H2.
apply H0.
assumption.
assumption.
intro.
unfold not in H.
apply H.
apply H2.
assumption.
Qed.
End S1.
