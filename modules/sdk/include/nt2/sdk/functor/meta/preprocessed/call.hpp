  template<class Tag, class A0, class Site> struct call<Tag(A0),Site> : std::tr1::result_of<functor<Tag,Site>(A0)> {}; template<class Tag, class A0 , class A1, class Site> struct call<Tag(A0 , A1),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1)> {}; template<class Tag, class A0 , class A1 , class A2, class Site> struct call<Tag(A0 , A1 , A2),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> struct call<Tag(A0 , A1 , A2 , A3),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44 , class A45, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44 , class A45 , class A46, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44 , class A45 , class A46 , class A47, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44 , class A45 , class A46 , class A47 , class A48, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4 , class A5 , class A6 , class A7 , class A8 , class A9 , class A10 , class A11 , class A12 , class A13 , class A14 , class A15 , class A16 , class A17 , class A18 , class A19 , class A20 , class A21 , class A22 , class A23 , class A24 , class A25 , class A26 , class A27 , class A28 , class A29 , class A30 , class A31 , class A32 , class A33 , class A34 , class A35 , class A36 , class A37 , class A38 , class A39 , class A40 , class A41 , class A42 , class A43 , class A44 , class A45 , class A46 , class A47 , class A48 , class A49, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 , A49),Site> : std::tr1::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12 , A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 , A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 , A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 , A49)> {};
