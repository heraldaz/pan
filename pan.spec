%define name pan
%define version 0.139
%define release 1

Summary:   The Pan Newsreader
Name:      %{name}
Version:   %{version}
Release:   %{?_without_gtkspell:nospell}%{release}
License:   GPL
Group:     Applications/Internet
URL:       http://pan.rebelbase.com/
Source:    http://pan.rebelbase.com/download/releases/%{version}/source/%{name}-%{version}.tar.bz2
Vendor:    ChimPanXi
Epoch:     1

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
BuildRequires: glib2-devel >= 2.17.6
BuildRequires: gmime-devel >= 
BuildRequires: gtk2-devel >= 2.16.0
%{!?_without_gtkspell:BuildRequires: gtkspell-devel >= 2.0.7}

Requires: glib2 >= 2.17.6
Requires: gmime >= 
Requires: gtk2 >= 2.16.0
%{!?_without_gtkspell:Requires: gtkspell >= 2.0.7}

Provides: %{name}

%description
Pan is a newsreader which attempts to be pleasant to new and advanced
users alike.  It has all the typical features found in newsreaders and
also has powerful filtering, handles large binaries newsgroups well,
supports multiple servers transparently, allows for offline reading,
and more.  It's also the only Unix newsreader to get a perfect score on
the Good Net-Keeping Seal of Approval evalutions.

%prep
%setup -q
%build
%configure --program-prefix="" %{?_without_gtkspell:--without-gtkspell}
make CFLAGS="$RPM_OPT_FLAGS"
%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
%find_lang %{name}
%clean
rm -rf $RPM_BUILD_ROOT

%files -f %{name}.lang
%defattr(-,root,root)
%doc AUTHORS COPYING ChangeLog README
%attr(755,root,root) %{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/pixmaps/*


%changelog

* Tue Aug 15 2006 Charles Kerr <charles@rebelbase.com>
- fixed rpmlint mixed-use-of-spaces-and-tabs by removing an aberant tab.
- fixed rpmlint macro-in-%%changelog by escaping the percents.
- fixed rpmlint setup-not-quiet by adding -q to setup.
- fixed rpmlint hardcoded-packager-tag warning by removing the packager tag.
- fixed rpmlint rpm-buildroot-usage and no-cleaning-of-buildroot
  warnings by moving rm -rf RPM_BUILD_ROOT from prep to install.

* Sun Nov 28 2004 Charles Kerr <charles@rebelbase.com>
- removed gnet requirement

* Thu Nov 27 2003 Charles Kerr <charles@rebelbase.com>
- Added FOO_REQUIRED to keep version numbers in sync with configure.in
- Added pcre and pcre-devel

* Thu Jul 31 2003 Christophe Lambin <chris@rebelbase.com>
- Merged nospell version into the main spec file. Build the 
  spell-disabled with 'rpmbuild --ba --without gtkspell pan.spec'
- Bumped gnet requirement to 2.0.4

  to build the spell packages by just doing 'rpmbuild  
* Sat Dec 6 2002 Charles Kerr <charles@rebelbase.com>
- Added pango requirement for 1.0.5 or higher.

* Sat Dec 4 2002 Charles Kerr <charles@rebelbase.com>
- Replaced ANNOUNCE with ANNOUNCE.html.
 
* Sat Oct 10 2002 Christophe Lambin <chris@rebelbase.com>
- Removed NEWS, since we maintain ANNOUNCE instead.

* Sat Aug 25 2002 Christophe Lambin <chris@rebelbase.com>
- Bumped gtkspell requirement to 2.0.2.

* Sat Aug 18 2002 Christophe Lambin <chris@rebelbase.com>
- Restrict to gtkspell 2.0.0 until 2.0.2 comes out.

* Wed Jul 10 2002 Christophe Lambin <chris@rebelbase.com>
- Added gtkspell.

* Sat May 1 2002 Christophe Lambin <chris@rebelbase.com>
- Added gtk2 dependencies.
- %%configure option to avoid creating execs like 'iX86-distro-linux-pan'.

* Sat Apr 6 2002 Christophe Lambin <chris@rebelbase.com>
- removed explicit copy of gettext's Makefile.in.in to support gettext 0.11.x.

* Sat Sep 22 2001 Charles Kerr <charles@rebelbase.com>
- Added gdk-pixbuf and -devel to Requires and BuildRequires
- Updated gtk/glib and -devel requirements

* Sat Aug 18 2001 Christophe Lambin <chris@rebelbase.com>
- fixes for RH 7.1 + Ximian Gnome 1.4
- allow single tarball to be used for both pan & pan-images
- use gettext 0.10.35's Makefile.in.in for po since it gives us DESTDIR

* Thu Aug 9 2001 Charles Kerr <charles@rebelbase.com>
- removed some dependencies that are better left implicit

* Mon Apr 23 2001 Charles Kerr <charles@rebelbase.com>
- merged in improvements from rh, mdk, and polish versions of pan.spec

* Sun Jun 25 2000 Charles Kerr <charles@rebelbase.com>
- added Vendor
- updated the description to match the README desc & FAQ

* Mon Jan 24 2000 Simon Piette
- changed the build section to allow building RPMS on non-x86 archs

* Sun Dec 12 1999 Jason Leach <leach@wam.umd.edu>
- changed the Summary string
- updated the description to match the README desc

* Wed Dec 1 1999 Charles Kerr <charles@rebelbase.com>
- added "-ggdb3" to CFLAGS so that it'll be easier to read backtraces
  submitted in bug reports

* Thu Nov 4 1999 Jason Leach <leach@wam.umd.edu>
- added gtk+-1.2.6 requirement (1.2.3 definitely breaks, might as well
  make it newest gtk+)

* Tue Nov 2 1999 Jason Leach <leach@wam.umd.edu>
- made .spec.in file to auto-generate .spec

* Sat Sep 25 1999 Leland Elie <lelie@airmail.net>
- created spec file.
