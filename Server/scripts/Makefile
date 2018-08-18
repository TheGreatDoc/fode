DIR_BUILD = obj

CXX = g++
CXXFLAGS = $(addprefix -I,$(DIRS_INCLUDE)) -O2
CXXFLAGS_SO = -shared -fPIC
DIRS_INCLUDE = StlPort

SO = \
    fonline_tla.so \
    fonline_tla_client.so \
    fonline_test.so \
    fonline_test_client.so \
    MySqlConnect.so

all: $(SO)

fonline_tla.so: $(DIR_BUILD)/server/fonline_tla.o
	$(CXX) $(CXXFLAGS_SO) -o $@ $<

fonline_tla_client.so: $(DIR_BUILD)/client/fonline_tla.o
	$(CXX) $(CXXFLAGS_SO) -o $@ $<

fonline_test.so: $(DIR_BUILD)/server/fonline_test.o
	$(CXX) $(CXXFLAGS_SO) -o $@ $< -lpython2.7

fonline_test_client.so: $(DIR_BUILD)/client/fonline_test.o
	$(CXX) $(CXXFLAGS_SO) -o $@ $<

MySqlConnect.so: $(DIR_BUILD)/server/MySqlConnect.o
	$(CXX) $(CXXFLAGS_SO) -o $@ $< $(shell mysql_config --libs)

$(DIR_BUILD)/client/%.o: %.cpp | $(DIR_BUILD)/client
	$(CXX) $(CXXFLAGS) -D__CLIENT -c $< -o $@

$(DIR_BUILD)/server/%.o: %.cpp | $(DIR_BUILD)/server
	$(CXX) $(CXXFLAGS) -D__SERVER -c $< -o $@

$(DIR_BUILD)/server/fonline_test.o: fonline_test.cpp | $(DIR_BUILD)/server
	$(CXX) $(CXXFLAGS) -I/usr/include/python2.7 -D__SERVER -c $< -o $@

$(DIR_BUILD)/server/MySqlConnect.o: MySqlConnect.cpp | $(DIR_BUILD)/server
	$(CXX) $(CXXFLAGS) -Imariadb_client/debian32/mariadbclient/include -D__SERVER -c $< -o $@

$(DIR_BUILD)/client $(DIR_BUILD)/mapper $(DIR_BUILD)/server: $(DIR_BUILD)
	@mkdir -p $@

$(DIR_BUILD):
	mkdir -p $@

clean:
	rm -f $(SO)
	rm -rf $(DIR_BUILD)

again: clean all
