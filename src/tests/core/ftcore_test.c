#include "ftcore.h"
#include "CUnit/Basic.h"

/*
 * extern FT_Library
 * ftcore_CreateFtLibrary(void);
 *
 * extern FT_Error
 * ftcore_DestroyFtLibrary(FT_Library ft_library);
 *
 * extern FT_Face
 * ftcore_CreateFace(FT_Library ft_library, const char *ft_fontpath, FT_Long ft_index);
 *
 * extern FT_Error
 * ftcore_DestroyFace(FT_Face ft_face);
 */

int init_suite(void) { return 0; }
int clean_suite(void) {return 0; }

void
ftcore_test_000(void)
{
	FT_Library ft_library = NULL;
	ft_library = ftcore_CreateFtLibrary();

	CU_ASSERT_NOT_EQUAL(ft_library, NULL);

	ftcore_DestroyFtLibrary(&ft_library);
	CU_ASSERT_EQUAL(ft_library, NULL);
}


void
ftcore_test_001(void)
{
	FT_Library  ft_library  = NULL;
	FT_Face     ft_face     = NULL;
	const char *ft_fontpath = NULL;
	FT_Long     ft_index    = 0;

	ft_library = ftcore_CreateFtLibrary();

	ft_face = ftcore_CreateFace(ft_library,
				    ft_fontpath,
				    ft_index);
	CU_ASSERT_EQUAL(ft_face, NULL);

	ftcore_DestroyFace(&ft_face);
	CU_ASSERT_EQUAL(ft_face, NULL);

	ftcore_DestroyFtLibrary(&ft_library);
}

int
register_tests(CU_pSuite pcu_suite)
{
	if(NULL == CU_add_test(pcu_suite, "ftcore_test_000", ftcore_test_000))
	{
		return -1;
	}

	if(NULL == CU_add_test(pcu_suite, "ftcore_test_001", ftcore_test_001))
	{
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	CU_pSuite pcu_suite = NULL;

	if(CUE_SUCCESS != CU_initialize_registry())
	{
		return CU_get_error();
	}

	pcu_suite = (CU_add_suite("ftcore test suite", init_suite, clean_suite));
	if(NULL == pcu_suite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if(register_tests(pcu_suite) != 0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Run all tests using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);

	CU_basic_run_tests();
	printf("\n");

	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	// Run all tests using the automated interface
	CU_automated_run_tests();
	CU_list_tests_to_file();

	// Run all tests using the console interface
	CU_console_run_tests();

	/* Clean up registry and return */
	CU_cleanup_registry();
	return CU_get_error();
}

