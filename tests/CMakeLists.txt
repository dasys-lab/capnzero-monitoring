cmake_minimum_required( VERSION 3.13 )
project( capnzero-monitoring-test )

set(SOURCES
      acceptancetest.cpp
      eventlistenertest.cpp
      monitoredsubscribertest.cpp
      monitoredpublishertest.cpp
    )

add_executable( ${PROJECT_NAME} ${SOURCES} )

target_include_directories( ${PROJECT_NAME}
                              PRIVATE
                                ${CMAKE_CURRENT_SOURCE_DIR}/../include
                                ${CMAKE_CURRENT_SOURCE_DIR}/mocks
                                ${CMAKE_CURRENT_SOURCE_DIR}/../submodules/capnzero/capnzero/include)

target_link_libraries( ${PROJECT_NAME}
                        PRIVATE
                          CONAN_PKG::gtest
                          capnp
                          capnzero
                          capnzero-monitoring
                          )

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)
