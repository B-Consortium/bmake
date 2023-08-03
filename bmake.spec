Name:           bmake
Version:        0.0.1
Release:        1%{?dist}
Summary:        A command-line tool to make C-Styled projects easily
Group:          Development/Tools
License:        B-License
URL:            https://github.com/B-Consortium/bmake
Source0: 	https://github.com/B-Consortium/bmake/archive/v%{version}.tar.gz
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)

%description
This command-line tool is used to make B-Consortium's C-Styled projects easily

%prep
%setup -q -n %{name}-%{version}

%build
make bmake

%install
install -d m0755 %{buildroot}%{_bindir}
make install prefix=%{buildroot}/usr

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%{_bindir}/bmake
%{_mandir}/man6/bmake.6%{ext_man}
