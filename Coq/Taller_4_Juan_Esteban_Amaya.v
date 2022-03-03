(* Taller 4 =( *)
(* Punto 1 *)
(* P: El ejercito marcha en contra del enemigo.
   Q: El ejercito tiene posibilidades de exito.
   R: El ejercito arrasara la capital enemiga.
   S: El ejercito se repliega rapidamente.
   T: El enemigo atacara su retraguardia.
   U: El ejercito ganara la guerra.
*)

Section Punto1.
Variables P Q R S T U: Prop.
Hypothesis H1: (P -> Q) /\ ( Q -> R ).
Hypothesis H2: P \/ S.
Hypothesis H3: ( S -> T ) /\ ( T -> ~U ).
Lemma UnicornioGuerrero: ~R -> ~U.
(* intuition. *)
intros.
intro.
apply H.
apply H1.
apply H1.
destruct H2.
assumption.
destruct H3.
apply  H6 in H0.
contradiction.
apply H5.
assumption.
Qed.
End Punto1.

(* Punto 2 *)
(*
  P: La fisica describe la naturaleza a base observables clasicos.
  Q: La fisica describe la naturaleza a base de estados abstractos.
  R: permite representar cosas intuitivamente.
  S: nos exige renunciar a la causalidad.
*)

Section Punto2.
Variables P Q R S: Prop.
Hypothesis H1: P \/ Q.
Hypothesis H2: P -> ( R /\ S ).
Hypothesis H3: Q -> ( ~R /\ ~S ).
Hypothesis H4: S -> ~R. 
Lemma UnicornioFisico: ~R <-> ~S.
(* intuition. *)
split.
intros.
intro.
apply H4.
assumption.
apply H2.
destruct H1.
assumption.
destruct H3.
assumption.
contradiction.
intros.
intro.
apply H.
apply H2.
destruct H1.
assumption.
destruct H3.
assumption.
contradiction.
Qed.
End Punto2.

(* Punto 3 *)
(*
  P: Los investigadores en linguistica tienen la razon.
  Q: Hubo mas de un dialecto en la antigua grecia.
  R: Llegaron diferentes tribus desde el norte en epocas distintas.
  S: Las tribus arribaron por el valle de rio Danubio.
  T: las excavaciones arqueologicas hubieran revelado trazas 
     de diferentes tribus en el valle del Rio Danubio.
*)

Section Punto3.
Variables P Q R S T: Prop.
Hypothesis H1: P -> Q.
Hypothesis H2: Q -> R.
Hypothesis H3: ~R \/ S.
Hypothesis H4: S -> T.
Hypothesis H5: ~T. 
Lemma UnicornioInvestigador: P -> ~Q.
(* intuition. *)
intros.
intro.
destruct H3.
apply H6.
apply H2.
assumption.
apply H5.
apply H4.
assumption.
Qed.
End Punto3.

(* Punto 4 *)
(*
  P: Sanchez cometio el crimen.
  Q: El crimen ocurrio despues de las 4:00 a.m.
  R: El crimen involucra a dos personas.
  S: Gomez cometio el crimen.
*)

Section Punto4.
Variables P Q R S: Prop.
Hypothesis H1: Q  -> ~P.
Hypothesis H2: ~Q -> ~S .
Hypothesis H3: ~S  -> R .
Lemma UnicornioAsesino: P -> R.
(* intuition. *)
intro.
apply H3.
apply H2.
intro.
apply H1.
assumption.
assumption.
Qed.
End Punto4.

(* Punto 5 *)
(*
  P : Norma va a su reunión del sabado por la mañana.
  Q : Norma debera levantarse temprano el sabado.
  R : Norma va al concierto de Gilberto Santarrosa el viernes por la noche.
  S : Norma llegara despues de la 1:00am.
  T : Norma trabaja despues de dormir menos de 5 horas.
*)

Section Punto5.
Variables P Q R S T : Prop.
Hypothesis H1 : P -> Q.
Hypothesis H2 : R -> S.
Hypothesis H3 : (S /\ Q) -> T.
Hypothesis H4 : ~T.
Lemma UnicornioFiestero : ~(R /\ P). (* Morgan *)
(* intuition. *)
intros.
intro.
destruct H.
apply H4.
apply H3.
split.
apply H2.
assumption.
apply H1.
assumption.
Qed.
End Punto5.

(* Punto 6 *)
Section Punto6.
Variables P Q R S T : Prop.
(*
  P: Miembro escoces.
  Q: Lleva sombreo.
  R: Usa falda
  S: Esta casado
  T: Van los domingos 
*)

Hypothesis H1 : ~P -> Q.
Hypothesis H2 : R \/ ~Q .
Hypothesis H3 : S -> ~T.
Hypothesis H4 : T <-> P.
Hypothesis H5 : R -> ( P /\ S ).
Hypothesis H6 : P -> R.
Lemma UnicornioEscoses: False. (* Inconsistencia *)
(* intuition. *)
apply H3.
destruct H2.
apply H5 in H.
destruct H.
assumption.
apply H in H1.
contradiction.
intros.
intro.
destruct H5.
apply H6.
assumption.
apply H3.
assumption.
apply H4.
assumption.
destruct H2.
destruct H5.
assumption.
apply H4.
assumption.
apply H in H1.
contradiction.
intros.
intro.
apply H.
apply H1.
intros.
intro.
apply H6 in H7.
apply H5 in H7.
destruct H7.
apply H4 in H7.
apply H3 in H8.
contradiction.
Qed.
End Punto6.