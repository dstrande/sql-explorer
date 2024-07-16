from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("qt/6.7.1")
        self.requires("libpqxx/7.9.1")
        self.requires("zlib/1.2.11")

    def layout(self):
        cmake_layout(self)