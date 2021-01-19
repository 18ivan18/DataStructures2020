#ifndef __PROB1_TESTS_H
#define __PROB1_TESTS_H

const double R = .1;

TEST_CASE("Insert into empty tree") {
    TONode* t = nullptr;
    CHECK(insert(t, 100, R));
    CHECK_EQ(printTree(t), "(100***)");
    eraseTree(t);
}

TEST_CASE("Insert into left subtree of a leaf") {
    TONode* t = new TONode(100);
    CHECK(insert(t, 50, R));
    CHECK_EQ(printTree(t), "(100(50***)**)");
    eraseTree(t);
}

TEST_CASE("Insert into mid subtree of a leaf") {
    TONode* t = new TONode(100);
    CHECK(insert(t, 95, R));
    CHECK_EQ(printTree(t), "(100*(95***)*)");
    eraseTree(t);
}

TEST_CASE("Insert into right subtree of a leaf") {
    TONode* t = new TONode(100);
    CHECK(insert(t, 150, R));
    CHECK_EQ(printTree(t), "(100**(150***))");
    eraseTree(t);
}

TEST_CASE("Refuse to insert element in a leaf if it already exists") {
    TONode* t = new TONode(100);
    CHECK_FALSE(insert(t, 100, R));
    eraseTree(t);
}

TEST_CASE("Series of inserts") {
    TONode* t = nullptr;

    CHECK(insert(t, 100, R));
    CHECK_EQ(printTree(t), "(100***)");

    CHECK(insert(t, 108, R));
    CHECK_EQ(printTree(t), "(100*(108***)*)");

    CHECK(insert(t, 150, R));
    CHECK_EQ(printTree(t), "(100*(108***)(150***))");
    
    CHECK(insert(t, 155, R));
    CHECK_EQ(printTree(t), "(100*(108***)(150*(155***)*))");

    CHECK(insert(t, 50, R));
    CHECK_EQ(printTree(t), "(100(50***)(108***)(150*(155***)*))");

    CHECK(insert(t, 110, R));
    CHECK_EQ(printTree(t), "(100(50***)(108*(110***)*)(150*(155***)*))");

    CHECK(insert(t, 40, R));
    CHECK_EQ(printTree(t), "(100(50(40***)**)(108*(110***)*)(150*(155***)*))");

    CHECK(insert(t, 166, R));
    CHECK_EQ(printTree(t), "(100(50(40***)**)(108*(110***)*)(150*(155***)(166***)))");

    CHECK(insert(t, 60, R));
    CHECK_EQ(printTree(t), "(100(50(40***)*(60***))(108*(110***)*)(150*(155***)(166***)))");

    eraseTree(t);
}

#endif
