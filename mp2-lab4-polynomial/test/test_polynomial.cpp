#include "polynomial.h"

#include <gtest.h>

TEST(Monom, monom_can_be_created_by_numbers)
{
	ASSERT_NO_THROW(Monom m(1.2, 1));
	Monom m(1.2, 1);
	EXPECT_EQ(1.2, m.getCoeff());
	EXPECT_EQ(1, m.getPower());
}

TEST(Monom, monom_can_be_created_by_strings)
{
	ASSERT_NO_THROW(Monom m("1.2", "1"));
	Monom m("1.2", "1");
	EXPECT_EQ(1.2, m.getCoeff());
	EXPECT_EQ(1, m.getPower());
}

TEST(Monom, monom_can_copy_itself)
{
	Monom m1(1.2, 1);
	ASSERT_NO_THROW(Monom m2(m1));
	Monom m2(m1);
	EXPECT_EQ(1.2, m2.getCoeff());
	EXPECT_EQ(1, m2.getPower());
}

TEST(Monom, monom_can_set_and_get)
{
	Monom m1(0,0);
	m1.setCoeff(1.2);
	m1.setPower(1);
	EXPECT_EQ(1.2, m1.getCoeff());
	EXPECT_EQ(1, m1.getPower());
}

TEST(Polynomial, polynom_can_be_created)
{
	ASSERT_NO_THROW(Polynomial p);
	Polynomial p;
	EXPECT_EQ(0, p.getSize());
}

TEST(Polynomial, polynom_can_be_copy)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	ASSERT_NO_THROW(Polynomial p2 = p1);
	Polynomial p2 = p1;
	EXPECT_EQ(2, p2.getSize());
	EXPECT_EQ(p2.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p2.returnMonom(1), Monom(2, 2));
}

TEST(Polynomial, polynom_can_be_copy2)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	ASSERT_NO_THROW(Polynomial p2(p1));
	Polynomial p2(p1);
	EXPECT_EQ(2, p2.getSize());
	EXPECT_EQ(p2.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p2.returnMonom(1), Monom(2, 2));
}

TEST(Polynomial, polynom_can_be_read)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	EXPECT_EQ(2, p1.getSize());
	EXPECT_EQ(p1.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p1.returnMonom(1), Monom(2, 2));
}

TEST(Polynomial, polynom_can_be_equal)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2 = p1;
	EXPECT_EQ(2, p2.getSize());
	EXPECT_EQ(p2.returnMonom(0), Monom(1,1));
	EXPECT_EQ(p2.returnMonom(1), Monom(2, 2));
}

TEST(Polynomial, polynom_can_equal_itself)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	p1 = p1;
	EXPECT_EQ(2, p1.getSize());
	EXPECT_EQ(p1.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p1.returnMonom(1), Monom(2, 2));
}

TEST(Polynomial, polynom_can_sum)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2+2*x^1");
	Polynomial p3 = p1 + p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(3, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(5, 2));
}

TEST(Polynomial, polynom_can_sum_polynoms_different_size)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 + p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(5, 2));
}

TEST(Polynomial, polynom_can_sum_polynoms_with_single_monom)
{
	Polynomial p1;
	p1.setPol("1*x^1");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 + p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(3, 2));
}

TEST(Polynomial, polynom_can_sum_polynoms_with_different_powers)
{
	Polynomial p1;
	p1.setPol("1*x^0+3*x^1");
	Polynomial p2;
	p2.setPol("0*x^2+10*x^3");
	Polynomial p3 = p1 + p2;
	EXPECT_EQ(4, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 0));
	EXPECT_EQ(p3.returnMonom(1), Monom(3, 1));
	EXPECT_EQ(p3.returnMonom(2), Monom(0, 2));
	EXPECT_EQ(p3.returnMonom(3), Monom(10, 3));
}

TEST(Polynomial, polynom_can_subtract)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2+2*x^1");
	Polynomial p3 = p1 - p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(-1, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(-1, 2));
}

TEST(Polynomial, polynom_can_subtract_polynoms_different_size)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 - p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(-1, 2));
}

TEST(Polynomial, polynom_can_subtract_polynoms_with_single_monom)
{
	Polynomial p1;
	p1.setPol("1*x^1");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 - p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 1));
	EXPECT_EQ(p3.returnMonom(1), Monom(-3, 2));
}

TEST(Polynomial, polynom_can_subtract_polynoms_with_different_powers)
{
	Polynomial p1;
	p1.setPol("1*x^0+3*x^1");
	Polynomial p2;
	p2.setPol("0*x^2+10*x^3");
	Polynomial p3 = p1 - p2;
	EXPECT_EQ(4, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(1, 0));
	EXPECT_EQ(p3.returnMonom(1), Monom(3, 1));
	EXPECT_EQ(p3.returnMonom(2), Monom(0, 2));
	EXPECT_EQ(p3.returnMonom(3), Monom(-10, 3));
}

TEST(Polynomial, polynom_can_multiply)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2+2*x^1");
	Polynomial p3 = p1 * p2;
	EXPECT_EQ(4, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(3, 3));
	EXPECT_EQ(p3.returnMonom(1), Monom(2, 2));
	EXPECT_EQ(p3.returnMonom(2), Monom(6, 4));
	EXPECT_EQ(p3.returnMonom(3), Monom(4, 3));
}

TEST(Polynomial, polynom_can_multiply_polynoms_different_size)
{
	Polynomial p1;
	p1.setPol("1*x^1+2*x^2");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 * p2;
	EXPECT_EQ(2, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(3, 3));
	EXPECT_EQ(p3.returnMonom(1), Monom(6, 4));
}

TEST(Polynomial, polynom_can_multiply_polynoms_with_single_monom)
{
	Polynomial p1;
	p1.setPol("1*x^1");
	Polynomial p2;
	p2.setPol("3*x^2");
	Polynomial p3 = p1 * p2;
	EXPECT_EQ(1, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(3, 3));
}

TEST(Polynomial, polynom_can_multiply_polynoms_with_different_powers)
{
	Polynomial p1;
	p1.setPol("1*x^0+3*x^1");
	Polynomial p2;
	p2.setPol("0*x^2+10*x^3");
	Polynomial p3 = p1 * p2;
	EXPECT_EQ(4, p3.getSize());
	EXPECT_EQ(p3.returnMonom(0), Monom(0, 2));
	EXPECT_EQ(p3.returnMonom(1), Monom(10, 3));
	EXPECT_EQ(p3.returnMonom(2), Monom(0, 3));
	EXPECT_EQ(p3.returnMonom(3), Monom(30, 4));
}