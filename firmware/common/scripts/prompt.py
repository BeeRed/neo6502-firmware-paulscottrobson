# ***************************************************************************************
# ***************************************************************************************
#
#      Name :      prompt.py
#      Authors :   Paul Robson (paul@robsons.org.uk)
#      Date :      22nd November 2023
#      Reviewed :  No
#      Purpose :   Prompt creator (counts builds etc.)
#
# ***************************************************************************************
# ***************************************************************************************

import sys
import git
#
#		This is the current version.
#
try:
    repo = git.Repo(search_parent_directories=True)
    version = repo.git.describe("--tags", "--always")
    if repo.is_dirty():
        version += " dirty"
except:
    version = "?"
print("//\n//\tThis file is automatically generated\n//")
print("#define PROMPT \"Version {0}\\r\"".format(version))