#
# Copyright (c) 2015, NVIDIA CORPORATION.  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

########## Make rule for test in34  ########


in34: run
	

fcheck.$(OBJX): $(SRC)/check_mod.f90
	-$(FC) -c $(FFLAGS) $(SRC)/check_mod.f90 -o fcheck.$(OBJX)

build:  $(SRC)/in34.f90 fcheck.$(OBJX)
	-$(RM) in34.$(EXESUFFIX) in34.$(OBJX) 
	@echo ------------------------------------ building test $@
	-$(FC) -c $(FFLAGS) $(LDFLAGS) $(SRC)/in34.f90 -o in34.$(OBJX)
	-$(FC) $(FFLAGS) $(LDFLAGS) in34.$(OBJX) fcheck.$(OBJX) $(LIBS) -o in34.$(EXESUFFIX)


run:
	@echo ------------------------------------ executing test in34
	in34.$(EXESUFFIX)

verify: ;

in34.run: run

