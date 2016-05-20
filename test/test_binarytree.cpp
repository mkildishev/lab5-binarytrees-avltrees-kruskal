#include <gtest.h>
#include <binarysearchtree.h>

TEST(bintrees, work_push_into_bst)
{
	node* newroot = new node();
	newroot->key = 1337;
	node* fakeroot = 0;
	WorkAroundSearch(newroot);
	ASSERT_NO_THROW(Push( fakeroot, newroot));


}