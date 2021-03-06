set(antlr4_folder "${CMAKE_CURRENT_SOURCE_DIR}/antlr4")
set(antlr4_cpp_folder "${antlr4_folder}/runtime/Cpp")
set(antlr4_jar "${antlr4_folder}/tool/target/antlr4-4.9.1-SNAPSHOT-complete.jar")
set(antlr4_demo "${antlr4_cpp_folder}/build/install/share/antlr4-demo")
set(antlr4_main "${antlr4_cpp_folder}/demo/Linux/main.cpp")

if(EXISTS "${antlr4_folder}/README.md")
    message(STATUS "${antlr4_folder}/README.md exists")
else()
    message(STATUS "${antlr4_folder}/README.md does not exist")
endif()

set(antlr4_jar_prebuilt "${CMAKE_CURRENT_SOURCE_DIR}/prebuilt/antlr4/antlr4-4.9.1-SNAPSHOT-complete.jar")

#
# -DskipTests=true is enough. The -pl line isn't accepted by cmake 3.18.20081302-MSVC_2 in my Windows. - holly
#
add_custom_target(antlr4 DEPENDS "${antlr4_jar}")
add_custom_command(OUTPUT "${antlr4_jar}"
  COMMAND "${CMAKE_COMMAND}" -D antlr4_jar="${antlr4_jar}" -D antlr4_jar_prebuilt="${antlr4_jar_prebuilt}" 
                             -D antlr4_folder="${antlr4_folder}" -D antlr4_jar_dir="${antlr4_folder}/tool/target"
                             -P "${CMAKE_CURRENT_SOURCE_DIR}/prepare_antlr4_jar.cmake")


add_custom_target(antlr4demo ALL DEPENDS ${antlr4_demo})

#
# Building in Windows requires --config option
#                                                   
# - holly
#
add_custom_command(OUTPUT ${antlr4_demo}
  COMMAND "${CMAKE_COMMAND}" -E make_directory build
  COMMAND "${CMAKE_COMMAND}" -DANTLR_JAR_LOCATION="${antlr4_jar}"
                             -DWITH_DEMO=True
                             -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                             -DCMAKE_INSTALL_PREFIX=build/install
                             -B build
  COMMAND "${CMAKE_COMMAND}" --build build --config Release
  COMMAND "${CMAKE_COMMAND}" --install build --config Release
  WORKING_DIRECTORY "${antlr4_cpp_folder}")

if(UPDATE_SUBMODULES)
  add_dependencies(antlr4 git-submodules)
endif()
add_dependencies(antlr4demo antlr4)

