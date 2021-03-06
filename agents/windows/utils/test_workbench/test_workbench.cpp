// test_workbench.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "gtest/gtest.h"
#include "ModuleControl.h"
#include <iostream>
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>

constexpr int kBufferSize = 512;
wchar_t G_PerfReaderPath[kBufferSize];

TEST(MakeFullPath, All)
{
	using namespace cma;

	EXPECT_TRUE( MakeFullPath<char>("path", "")== std::string(""));					// empty names not allowed

	// data to use in tests
	std::string empty = "";
	std::string normal = "n";
	std::string with_back_slash = "n\\";
	std::string with_slash = "n/";
	std::string fname = "f";

	EXPECT_EQ( MakeFullPath(empty, fname), fname );								// "f"
	EXPECT_EQ( MakeFullPath(normal, fname), normal + "/" + fname);				// "n/f"
	EXPECT_EQ( MakeFullPath(with_slash, fname), normal + "/" + fname);			// "n/f"
	EXPECT_EQ( MakeFullPath(with_back_slash, fname), normal + "\\" + fname);	// "n\\f"

}


TEST(IsFileExist, All)
{
	using namespace cma;
	using namespace cma::wnd;
	
	// verification that all folders are ready for testing
	EXPECT_TRUE(IsFileExist(MakeFullPath(kLocalFolder, test::kLocal)));
	EXPECT_TRUE(IsFileExist(MakeFullPath(kPluginsFolder, test::kPlugin)));
	EXPECT_TRUE(IsFileExist(MakeFullPath(kUtilsFolder, test::kUtil)));
	EXPECT_FALSE( IsFileExist(MakeFullPath(kUtilsFolder, test::kUtil)+L"cc") );
}

TEST(FindModule, All)
{
	using namespace cma;
	using namespace cma::wnd;

	// verification that all folders are ready for testing
	EXPECT_TRUE( FindModule( kLocalFolder,  test::kLocal)  == MakeFullPath(kLocalFolder, test::kLocal));
	EXPECT_TRUE( FindModule( kPluginsFolder,test::kPlugin) == MakeFullPath(kPluginsFolder, test::kPlugin));
	EXPECT_TRUE( FindModule( kUtilsFolder,  test::kUtil)   == MakeFullPath(kUtilsFolder, test::kUtil));

	EXPECT_TRUE( FindModule( kUtilsFolder,  test::kLocal) == std::wstring(L""));	// not found
}

TEST(RunModule, All)
{
	using namespace cma;
	using namespace cma::wnd;

	auto result = cma::RunModule(G_PerfReaderPath, L"help");
	EXPECT_TRUE(result);

	result = cma::RunModule(G_PerfReaderPath, L"510.tmp 510");
	EXPECT_TRUE(result);

	constexpr const wchar_t* const counter = L"510";
	auto fname = cma::BuildTmpProcIdFileName( counter );
	EXPECT_TRUE(fname[0]);
	if (fname[0])
	{
		result = cma::RunModule(G_PerfReaderPath, fname + L" " + counter);
		EXPECT_TRUE(result);
		EXPECT_TRUE(cma::IsFileExist(fname));
		auto data_block_bad = cma::ReadFile((fname+ L"x").c_str());
		EXPECT_EQ(data_block_bad.data_, nullptr);
		EXPECT_EQ(data_block_bad.len_, 0);

		auto data_block = cma::ReadFile(fname.c_str());
		EXPECT_NE(data_block.data_, nullptr);
		EXPECT_NE(data_block.len_, 0);

		DeleteFile(fname.c_str());
	}

}


TEST(VerifyAspects, OpenCloseEventLog)
{
	auto ret = ::OpenEventLogW(NULL, L"Application");
	EXPECT_TRUE(ret != NULL);
	if (ret == 0)
		::CloseEventLog(ret);

}



int wmain(int argc, wchar_t **argv)
{
	;
	;
	;
	if (argc < 2)
	{
		printf("Need Path for Perf_reader.exe" );
		return 1;
	}

	wcscpy_s(G_PerfReaderPath, kBufferSize, argv[1]);
    std::cout << "Hello World!\n"; 
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

