from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    default_options = {"qt*:shared": True}

    def requirements(self):
        self.requires("qt/6.7.1")
        self.requires("libpqxx/7.9.1")

    def layout(self):
        cmake_layout(self)