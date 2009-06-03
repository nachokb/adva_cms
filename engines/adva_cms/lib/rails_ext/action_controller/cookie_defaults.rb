# Makes cookies hash assume default domain/path. Add "defaults" hash to
# ActionController::CookieJar.
#
# Put this into an initializer:
#   ActionController::CookieJar.defaults[:domain] = ".example.com"
#
# then this in some controller:
#   cookies['uname'] = "foo"
# is equivalent to:
#   cookies['uname'] = { :value = "foo", :domain => ".example.com" }
#
# FIXME: This shouldn't be necessary. Don't forget to put
#  ActionController::Base.session = {
#    ...
#  }.reverse_merge! ActionController::CookieJar.defaults
#
# in your session_store initializer, and
#  Cookie.defaultDomain = ".domain.com"
#
# in javascripts/application.js if you are using Javascript with cookies, as Adva does by default; FIXME: neither should this be necessary

ActionController::CookieJar.class_eval do
  cattr_accessor :defaults
  self.defaults = { :path => '/' }
end

module Adva
  module CookieJarDefaults
    # TODO use include_into (howto alias_method_chain :[]=???)
    def self.included(base)
      base.class_eval do
        include InstanceMethods
        alias_method :set_without_defaults, :[]=
        alias_method :[]=, :set_with_defaults
      end
    end

    module InstanceMethods
      def set_with_defaults(key, options)
        if options.is_a?(Hash)
          options.symbolize_keys!
        else
          options = { :value => options }
        end

        options.reverse_merge! ActionController::CookieJar.defaults
        set_without_defaults(key.to_s, options) # super :(
      end
    end
  end
end
ActionController::CookieJar.send :include, Adva::CookieJarDefaults
