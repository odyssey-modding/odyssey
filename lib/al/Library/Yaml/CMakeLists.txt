add_subdirectory(Writer)
target_sources(odyssey PRIVATE
        ByamlContainerHeader.cpp
        ByamlContainerHeader.h
        ByamlData.cpp
        ByamlData.h
        ByamlHeader.cpp
        ByamlHeader.h
        ByamlIter.cpp
        ByamlIter.h
        ByamlUtil.cpp
        ByamlUtil.h
)


