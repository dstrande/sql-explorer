from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake, cmake_layout
from conan.tools.build import check_min_cppstd


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    default_options = {"qt*:shared": True}

    def requirements(self):
        self.requires("qt/6.7.1")
        self.requires("libpqxx/7.9.1")
        
    def validate(self):
        if self.info.settings.compiler.cppstd:
            check_min_cppstd(self, "17")

    def layout(self):
        cmake_layout(self)
        
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
